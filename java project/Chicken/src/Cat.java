import java.awt.Image;

public class Cat {
	public int x;
	public int y;
	public int width;
	public int height;
	public static int SPEED = 6;
	
	private Image image;
	
	public Cat() {
		x		= -1000;
		y		= -1000;
	}
	
	public void update() {
		y		-= App.speed;
	}
    public Render getRender() {
        Render r = new Render();
        r.x = x;
        r.y = y;

        if (image == null) {
            image = Util.loadImage("lib/cat.png");
            width = image.getWidth(null);
            height = image.getHeight(null);
        }
        r.image = image;

        return r;
    }

    public boolean collides(int _x, int _y, int _width, int _height) {

        int margin = 2;

        if (_y + _height - margin > y && _y + margin < y + height) {

            if (_x + _width - margin > x && _x + _width + margin < x+width ) {
                return true;
            }
        }

        return false;
    }
}
