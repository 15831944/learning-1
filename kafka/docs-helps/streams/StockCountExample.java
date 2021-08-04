package stream;

import org.apache.kafka.common.serialization.Serdes;
import org.apache.kafka.streams.KafkaStreams;
import org.apache.kafka.streams.KeyValue;
import org.apache.kafka.streams.StreamsConfig;
import org.apache.kafka.streams.kstream.KStream;
import org.apache.kafka.streams.kstream.KStreamBuilder;

import java.util.Arrays;
import java.util.Properties;
import java.util.regex.Pattern;

public class StockCountExample {
    static public final class TradeSerde extends WrapperSerde<Trade> {
        public TradeSerde() {
            super(new JsonSerializer<Trade>(), new JsonDeserializer<Trade>(Trade.class));
        }
    }

    public static void main(String[] args) throws Exception {
        Properties props = new Properties();
        props.put(StreamsConfig.APPLICATION_ID_CONFIG, "stockstat");
        props.put(StreamsConfig.BOOTSTRAP_SERVERS_CONFIG, Constants.BROKER);
        props.put(StreamsConfig.KEY_SERDE_CLASS_CONFIG, Serdes.String().getClass().getName());
        props.put(StreamsConfig.VALUE_SERDE_CLASS_CONFIG, TradeSerde.class.getName());
        KStream<TickerWindow, TradeStats> stats = source.groupByKey()
                .aggregate(TradeStats::new,
        (k, v, tradestats) -> tradestats.add(v),
        TimeWindows.of(5000).advanceBy(1000),
        new TradeStatsSerde(),
        "trade-stats-store")
                .toStream((key, value) -> new TickerWindow(key.key(),
                        key.window().start()))
                .mapValues((trade) -> trade.computeAvgPrice());

        stats.to(new TickerWindowSerde(), new TradeStatsSerde(),
                "stockstats-output");
    }
}