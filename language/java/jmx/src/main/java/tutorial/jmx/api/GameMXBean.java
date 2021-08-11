package tutorial.jmx.api;

public interface GameMXBean {
    void playFootball(String clubName);

    String getPlayerName();

    void setPlayerName(String playerName);
}
