import java.awt.event.KeyEvent;
import java.util.ArrayList;
import java.util.Iterator;

public class Game {

    public static final int home_DELAY = 100;

    private Boolean paused;

    private int pauseDelay;
    private int restartDelay;
    private int homeDelay;

    private Bird bird;
    private Cat cat;
    private ArrayList<Home> homes;
    private ArrayList<Egg> eggs;
    private Keyboard keyboard;

    public int score;
    public Boolean gameover;
    public Boolean started;
    public Integer level;
    public static long lastEgg = System.currentTimeMillis()/10;

    public Game() {
        keyboard = Keyboard.getInstance();
        restart();
    }

    public void restart() {
        paused = false;
        started = false;
        gameover = false;

        score = 0;
        pauseDelay = 0;
        restartDelay = 0;
        homeDelay = 0;
        level	= 1;

        bird = new Bird();
        cat		= new Cat();
        homes = new ArrayList<Home>();
        eggs = new ArrayList<Egg>();
    }

    public void update() {
        watchForStart();

        if (!started)
            return;

        watchForPause();
        watchForReset();

        if (paused)
            return;

        bird.update();
        watchForLevel();

        if (gameover)
            return;

        watchForEggThrow();
        moveCat();
        moveHomes();
        moveEggs();
        checkForCollisions();
        watchForLevelStatus();
    }

    public ArrayList<Render> getRenders() {
        ArrayList<Render> renders = new ArrayList<Render>();
        renders.add(new Render(0, 0, "lib/background.png"));
        for (Home home : homes)
            renders.add(home.getRender());
        for (Egg egg : eggs)
        	renders.add(egg.getRender());
        renders.add(bird.getRender());
        renders.add(cat.getRender());
        return renders;
    }

    private void watchForStart() {
        if (!started && keyboard.isDown(KeyEvent.VK_ENTER)) {
            started = true;
        }
    }

    private void watchForPause() {
        if (pauseDelay > 0)
            pauseDelay--;

        if (keyboard.isDown(KeyEvent.VK_P) && pauseDelay <= 0) {
            paused = !paused;
            pauseDelay = 10;
        }
    }

    private void watchForReset() {
        if (restartDelay > 0)
            restartDelay--;

        if (keyboard.isDown(KeyEvent.VK_R) && restartDelay <= 0) {
            restart();
            restartDelay = 10;
            return;
        }
    }
    private void watchForEggThrow() {
    	if(keyboard.isDown(KeyEvent.VK_SPACE)) {
    		if(lastEgg+Egg.interval>(System.currentTimeMillis()/10))
    			return;
    		lastEgg		= System.currentTimeMillis()/10;
    		Egg egg		= new Egg(bird.direction, bird.x, bird.y);
    		eggs.add(egg);
    	}
    }
    private void watchForLevel() {
    	if(keyboard.isDown(KeyEvent.VK_ADD)) {
    		score++;
    	}
    	if(keyboard.isDown(KeyEvent.VK_SUBTRACT)) {
    		score--;
    	}
    }
    
    private void watchForLevelStatus() {
    	level		= (int) Math.ceil(score/100);
    	level++;
    	App.speed	= level*App.SPEED;
    }
    
    private void moveEggs() {
    	for(Egg egg : eggs) {
    		egg.update();
    	}
    	checkForCollisionsOfEggs();
    }

    private void moveHomes() {
        homeDelay	-= level;

        if (homeDelay < 0) {
            homeDelay = home_DELAY;
            Home leftHouse = null;
            Home rightHouse = null;

            // Look for homes off the screen
            for (Home home : homes) {
                if (home.y + home.height < 0) {
                    if (leftHouse == null && home.orientation.equals("left")) {
                        leftHouse = home;
                    }
                    if (rightHouse == null && home.orientation.equals("right")) {
                        rightHouse = home;
                    }
                }
            }

            if (leftHouse == null) {
            	int ran		= ((int)(Math.random()*10))%2;
                Home home = new Home("left", ran==0 ? "big" : "small");
                homes.add(home);
                leftHouse = home;
            } else {
                leftHouse.reset();
            }

            if (rightHouse == null) {
            	int ran		= ((int)(Math.random()*10))%2;
                Home home = new Home("right", ran==0 ? "big" : "small");
                homes.add(home);
                rightHouse = home;
            } else {
                rightHouse.reset();
            }

            leftHouse.x = 0;
            rightHouse.x= App.WIDTH-rightHouse.width;
            leftHouse.y = App.WIDTH+(int)(Math.random()*300);
            rightHouse.y = App.WIDTH+(int)(Math.random()*300);
        }

        for (Home home : homes) {
            home.update();
        }
    }
    
    private void moveCat() {
    	if(cat.y+cat.height<0) {
    		cat.y		= ((int)(Math.random()*1000))+App.HEIGHT;
    		cat.x		= ((int)(Math.random()*1000))%(App.WIDTH-200)+100;
    	}
    	cat.update();
    }

    private void checkForCollisions() {

        for (Home home : homes) {
            if (home.collides(bird.x, bird.y, bird.width, bird.height)) {
                gameover = true;
                bird.dead = true;
            }
        }
        if(cat.collides( bird.x, bird.y, bird.width, bird.height)) {
        	gameover	= true;
        	bird.dead	= true;
        }

    }
    private void checkForCollisionsOfEggs() {
        for (Home home : homes) {
        	for(Iterator<Egg> iterator = eggs.iterator(); iterator.hasNext();) {
        		Egg egg		= iterator.next();
        		try {
	                if (home.collides(egg.x, egg.y, egg.width, egg.height)) {
	                	if(home.size=="small")
	                		score		+= 10;
	                	else
	                		score++;
	                	iterator.remove();
	                }
	                if(egg.x<0 || egg.x > App.WIDTH) {
	                	iterator.remove();
	                }
        		} catch (Exception e) {

				}
        	}
        }
    }
}   
