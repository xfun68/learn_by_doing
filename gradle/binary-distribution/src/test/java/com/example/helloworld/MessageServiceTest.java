package com.example.helloworld;

import org.junit.Before;
import org.junit.Test;

import static org.hamcrest.CoreMatchers.*;
import static org.junit.Assert.assertThat;

public class MessageServiceTest {
    private MessageService messageService;

    @Before
    public void setUp() {
        messageService = new MessageService();
    }

    @Test
    public void getMessage_should_return_hello_world() {
        String message = messageService.getMessage();
        assertThat(message, is(equalTo("Hello World!")));
    }
}
