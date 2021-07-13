package certification.defaultinterfaces;

public class Implementations {
	public static void main(String[] args) {
		new TwoInterfacesWithSameDefaultMethodCorrect().print();
		new TwoInterfacesOneExtendsSameDefaultMethod().print();
		new SecondLevel01_01().print();
		new SecondLevel01_02Correct().print();
		new SecondLevel01_0102_01_02().print();
		new SecondLevel01_0102_SecondLevel01_01Correct().print();
		new DiamondProblemFirstLEvel01Correct().print();
	}
}
/*
class TwoInterfacesWithSameDefaultMethodWrong implements IFirstLevel01,IFirstLevel02{

}
*/
class TwoInterfacesWithSameDefaultMethodCorrect implements IFirstLevel01, IFirstLevel02 {
	public void print() {
		System.out.println("reimplemented");
	}
	
}

class TwoInterfacesOneExtendsSameDefaultMethod extends FirstLevelClass implements IFirstLevel01,IFirstLevel02 {
	
}


class SecondLevel01_01 implements ISecondLevel01_01, IFirstLevel01 {
	
}

/*
class SecondLevel01_02Wrong implements ISecondLevel01_01, IFirstLevel02 {
	
}
*/

class SecondLevel01_02Correct implements ISecondLevel01_01, IFirstLevel02 {
	public void print() {
		System.out.println("Second Level 01_02 Correct");
	}
}

class SecondLevel01_0102_01_02 implements ISecondLevel01_0102, IFirstLevel01,IFirstLevel02 {
	
}

/*
class SecondLevel01_0102_SecondLevel01_01Wrong implements ISecondLevel01_0102,ISecondLevel01_01 {
	
}
*/
class SecondLevel01_0102_SecondLevel01_01Correct implements ISecondLevel01_0102,ISecondLevel01_01 {
	public void print() {
		System.out.println("SecondLevel01_0102_SecondLevel01_01Correct");
	}
}
/*
class DiamondProblemFirstLEvel01Wrong implements ISecondLevel01_01,ISecondLevel02_01 {
	
}
*/

class DiamondProblemFirstLEvel01Correct implements ISecondLevel01_01,ISecondLevel02_01 {
	public void print() {
		System.out.println("DiamondProblemFirstLEvel01Correct");
	}
}