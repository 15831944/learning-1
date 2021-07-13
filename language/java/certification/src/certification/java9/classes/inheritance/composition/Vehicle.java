package certification.java9.classes.inheritance.composition;

public class Vehicle {
	private int weightPounds;
	private int horsePower;
	private SpeedModel speedModel;

	public Vehicle(int weight, int power) {
		this.weightPounds = weight;
		this.horsePower = power;
	}
	public void setSpeedModel(SpeedModel speedModel) {
		this.speedModel = speedModel;
	}
	public double getSpeedMph(double timeSec) {
		return this.speedModel.getSpeedMph(timeSec, weightPounds, horsePower);
	}
}
