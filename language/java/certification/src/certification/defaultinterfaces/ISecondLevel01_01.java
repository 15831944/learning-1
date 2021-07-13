package certification.defaultinterfaces;

public interface ISecondLevel01_01 extends IFirstLevel01 {

	default void print() {
		System.out.println("Second level 01 01");
	}
}
