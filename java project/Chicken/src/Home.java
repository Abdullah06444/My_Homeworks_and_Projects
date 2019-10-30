import java.awt.Image;

public class Home {

    public int x;
    public int y;
    public int width;
    public int height;

    public String orientation;
    public String size;

    private Image image;

    public Home(String orientation, String size) {
        this.orientation = orientation;
        this.size		= size;
        reset();
    }

    public void reset() {
        y = App.HEIGHT + 2;

    }

    public void update() {
        y -= App.speed;
    }

    public boolean collides(int _x, int _y, int _width, int _height) {

        int margin = 2;

        if (_y + _height - margin > y && _y + margin < y + height) {

            if (orientation.equals("right") && _x + _width > x) {
                return true;
            } else if (orientation.equals("left") && _x < x + width) {
                return true;
            }
        }

        return false;
    }

    public Render getRender() {
        Render r = new Render();
        r.x = x;
        r.y = y;

        if (image == null) {
            image = Util.loadImage("lib/home-" + orientation + "-" + size + ".png");
            width = image.getWidth(null);
            height = image.getHeight(null);
        }
        r.image = image;

        return r;
    }
}
