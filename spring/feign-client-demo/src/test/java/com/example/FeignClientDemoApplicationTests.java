package com.example;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.http.ResponseEntity;
import org.springframework.test.context.junit4.SpringRunner;

import java.util.UUID;

@RunWith(SpringRunner.class)
@SpringBootTest
public class FeignClientDemoApplicationTests {

	@Autowired
	private StoreClient storeClient;

	@Test
	public void check_test() {
		String id = String.valueOf(UUID.randomUUID());
		ResponseEntity responseEntity = storeClient.checkin(id);
		System.out.println("#panda# " + responseEntity);
	}

}
