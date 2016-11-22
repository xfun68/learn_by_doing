package com.example;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.netflix.feign.EnableFeignClients;

@EnableFeignClients
@SpringBootApplication
public class FeignClientDemoApplication {

	public static void main(String[] args) {
		SpringApplication.run(FeignClientDemoApplication.class, args);
	}
}

