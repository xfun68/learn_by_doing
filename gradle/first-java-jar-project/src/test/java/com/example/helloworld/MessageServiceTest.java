package com.example.helloworld;

import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class MessageServiceTest {

    private MessageService messageService;

    @Before
    public void setUp() throws Exception {
        messageService = new MessageService();
    }

    @Test
    public void testGetMessage() throws Exception {
        assertEquals("Hello World!", messageService.getMessage());
    }
}
