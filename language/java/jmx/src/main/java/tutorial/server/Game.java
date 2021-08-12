package tutorial.server;

import tutorial.server.api.GameMXBean;

public class Game implements GameMXBean {
    private String playerName;
    @Override
    public void playFootball(String clubName) {
        System.out.println(this.playerName + " playing football for " + clubName);
    }

    @Override
    public String getPlayerName() {
        System.out.println("Return payerName " + this.playerName);
        return playerName;
    }

    @Override
    public void setPlayerName(String playerName) {
        System.out.println("Set playerName to value " + playerName);
        this.playerName = playerName;
    }
}
