package certification.serialization.base;

public class Prize {

	private String type;
	private int place;
	
	public Prize() {
		type = "none";
		place = 0;
	}
	
	public Prize(final String type, final int place) {
		this.type = type;
		this.place = place;
	}
	
	public void setType(final String type) {
		this.type = type;
	}
	
	public String getType() {
		return type;
	}
	
	public void setPlace(final int place) {
		this.place = place;
	}
	
	public int getPlace() {
		return place;
	}
}
