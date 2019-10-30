import java.awt.Image;
import java.awt.event.KeyEvent;
import java.awt.geom.AffineTransform;
import java.util.ArrayList;

public class Bird {

    public int x;
    public int y;
    public int width;
    public int height;

    public boolean dead;

    public double yvel;
    public double gravity;
    public int direction		= 1;

    private double rotation;
    
    private String imageFile	= "lib/chicken_right.png";

    private Image image;
    private Keyboard keyboard;

    public Bird() {
        x = 100;
        y = 150;
        yvel = 0;
        width = 45;
        height = 32;
        gravity = 0.5;
        rotation = 0.0;
        dead = false;

        keyboard	= Keyboard.getInstance();
    }

    public void update() {
        //yvel += gravity;

        //if (jumpDelay > 0)
         //   jumpDelay--;

    	if(keyboard.isDown(KeyEvent.VK_LEFT))
    		x	-= 5;
    	if(keyboard.isDown(KeyEvent.VK_RIGHT))
    		x	+= 5;

        /*if (!dead && keyboard.isDown(KeyEvent.VK_SPACE) && jumpDelay <= 0) {
            yvel = -15;
            jumpDelay = 15;
        }*/

        //y += (int)yvel;
    }

    public Render getRender() {
        Render r = new Render();
        r.x = x;
        r.y = y;
        
    	if(keyboard.isDown(KeyEvent.VK_LEFT)) {
    		imageFile	= "lib/chicken_left.png";
    		direction	= -1;
    	}
    	if(keyboard.isDown(KeyEvent.VK_RIGHT)) {
            imageFile	= "lib/chicken_right.png";
            direction	= 1;
    	}

        image = Util.loadImage(imageFile);     
        
        r.image = image;

        r.transform = new AffineTransform();
        r.transform.translate(x + width / 2, y + height / 2);
        r.transform.rotate(rotation);
        r.transform.translate(-width / 2, -height / 2);


        return r;
    }
}
