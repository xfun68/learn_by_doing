package com.example;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.cloud.context.config.annotation.RefreshScope;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

@RefreshScope
@RestController
public class MessageController {

    @Value("${message:Hello in Application default}")
    private String message;

    @Value("${name:Name in App default}")
    private String name;

    @RequestMapping(value = "/message", method = RequestMethod.GET)
    public String getMessage() {
        return String.format("{message: %s, name: %s}", this.message, this.name);
    }
}
