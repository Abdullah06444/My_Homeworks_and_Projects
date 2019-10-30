import java.awt.Image;

public class Egg {
	public int x;
	public int y;
	public int width;
	public int height;
	public static int SPEED = 6;
	public static int interval = 20;
	
	public int direction;
	private Image image;
	
	public Egg(int direction, int x, int y) {
		this.direction		= direction;
		this.x				= x;
		this.y				= y;
	}
	
	public void update() {
		if(direction==1)
			x		+= Egg.SPEED;
		else
			x		-= Egg.SPEED;
	}
    public Render getRender() {
        Render r = new Render();
        r.x = x;
        r.y = y;

        if (image == null) {
            image = Util.loadImage("lib/egg.png");
            width = image.getWidth(null);
            height = image.getHeight(null);
        }
        r.image = image;

        return r;
    }
}
