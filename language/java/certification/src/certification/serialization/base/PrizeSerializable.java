package certification.serialization.base;

import java.io.Serializable;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class PrizeSerializable extends Prize implements Serializable{

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	public PrizeSerializable() {
	}
	
	public PrizeSerializable(final String type, final int place) {
		super(type, place);
	}
	
	private void readObject(ObjectInputStream is) {
		try {
			is.defaultReadObject();
			setType((String) is.readObject());
			setPlace(is.readInt());
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private void writeObject(ObjectOutputStream os) {
		try {
			os.defaultWriteObject();
			os.writeObject(getType());
			os.writeInt(getPlace());
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
