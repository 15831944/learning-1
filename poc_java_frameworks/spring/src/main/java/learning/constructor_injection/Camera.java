package learning.constructor_injection;

public class Camera {
    private int resolution;
    private String mode;
    private boolean smileShot;
    private boolean flash;

    public Camera(int resolution, String mode, boolean smileShot) {
        this.resolution = resolution;
        this.mode = mode;
        this.smileShot = smileShot;
        this.flash = false;
    }

    public Camera(int resolution, String mode, boolean smileShot, boolean flash) {
        this.resolution = resolution;
        this.mode = mode;
        this.smileShot = smileShot;
        this.flash = flash;
    }

    public void showSettings() {
        System.out.println("Resolution:" + resolution + " px mode:" + mode + " smileShot:" + smileShot + " flash:" + flash);
    }
}
