package certification.defaultinterfaces;

public interface ISecondLevel01_0102 extends IFirstLevel01, IFirstLevel02 {
	default void print() {
		System.out.println("Second Level 01 0102");
	}
}
