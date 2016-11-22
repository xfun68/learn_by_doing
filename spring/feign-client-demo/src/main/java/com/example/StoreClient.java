package com.example;

import org.springframework.cloud.netflix.feign.FeignClient;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

@FeignClient("gocd")
@RequestMapping(path = "/checkin")
interface StoreClient {

	@RequestMapping(method = RequestMethod.POST)
	public ResponseEntity checkin(@RequestBody String message);

}
