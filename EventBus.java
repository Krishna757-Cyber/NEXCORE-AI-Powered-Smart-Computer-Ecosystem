package com.nexcore.orchestrator;
import java.util.*;
import java.util.concurrent.ConcurrentHashMap;
import java.util.function.Consumer;

public class EventBus {
    private final Map<String, List<Consumer<String>>> subs = new ConcurrentHashMap<>();

    public void subscribe(String topic, Consumer<String> cb) {
        subs.computeIfAbsent(topic, k -> new ArrayList<>()).add(cb);
    }

    public void publish(String topic, String msg) {
        List<Consumer<String>> consumers = subs.getOrDefault(topic, Collections.emptyList());
        for (Consumer<String> c : consumers) c.accept(msg);
    }
}