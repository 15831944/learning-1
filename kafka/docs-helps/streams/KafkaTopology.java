package stream;

import org.apache.kafka.common.serialization.Serdes;

public class KafkaTopology {
    public static void main(String...args) {
        KStream<Integer, PageView> views =
                builder.stream(Serdes.Integer(),
                        new PageViewSerde(), Constants.PAGE_VIEW_TOPIC);
        KStream<Integer, Search> searches =
                builder.stream(Serdes.Integer(), new SearchSerde(),
                        Constants.SEARCH_TOPIC);
        KTable<Integer, UserProfile> profiles =
                builder.table(Serdes.Integer(), new ProfileSerde(),
                        Constants.USER_PROFILE_TOPIC, "profile-store");

        KStream<Integer, UserActivity> viewsWithProfile = views.leftJoin(profiles,
        (page, profile) -> new UserActivity(profile.getUserID(),
                profile.getUserName(), profile.getZipcode(),
                profile.getInterests(), "", page.getPage()));

        KStream<Integer, UserActivity> userActivityKStream =
                viewsWithProfile.leftJoin(searches,
        (userActivity, search) ->
                userActivity.updateSearch(search.getSearchTerms()),
        JoinWindows.of(1000), Serdes.Integer(),
                new UserActivitySerde(), new SearchSerde());
    }
}
