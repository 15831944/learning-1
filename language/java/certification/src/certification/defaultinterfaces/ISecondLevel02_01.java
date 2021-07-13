package certification.defaultinterfaces;

public interface ISecondLevel02_01 extends IFirstLevel01 {

	default void print() {
		System.out.println("second level 02_01");
	}
}
