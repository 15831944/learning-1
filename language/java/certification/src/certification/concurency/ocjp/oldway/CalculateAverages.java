package certification.concurency.ocjp.oldway;

public class CalculateAverages implements Runnable{
    private double[] scores;
    public CalculateAverages(double[] scores) {
        this.scores = scores;
    }

    public void run() {
        double average = 0.0;
        for (int i = 0; i < scores.length; i++)
            average +=scores[i];
        average /= scores.length;
        System.out.println("Average is = " + average);
    }
}
