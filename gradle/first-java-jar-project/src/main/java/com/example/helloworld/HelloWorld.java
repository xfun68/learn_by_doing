package com.example.helloworld;

import java.util.logging.Logger;

public class HelloWorld {
    private static final Logger LOGGER = Logger.getLogger(String.valueOf(HelloWorld.class));

    public static void main(String[] args) {
        MessageService messageService = new MessageService();
        String message = messageService.getMessage();
        LOGGER.info("Received message: " + message);
    }
}
