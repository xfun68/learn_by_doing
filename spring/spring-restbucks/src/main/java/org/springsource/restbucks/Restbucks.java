/*
 * Copyright 2013-2016 the original author or authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package org.springsource.restbucks;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;
import org.springframework.hateoas.UriTemplate;
import org.springframework.hateoas.hal.CurieProvider;
import org.springframework.hateoas.hal.DefaultCurieProvider;
import org.springframework.scheduling.annotation.EnableAsync;

/**
 * Central application class containing both general application and web configuration as well as a main-method to
 * bootstrap the application using Spring Boot.
 * 
 * @see #main(String[])
 * @see SpringApplication
 * @author Oliver Gierke
 */
@SpringBootApplication
@EnableAsync
public class Restbucks {

	public static String CURIE_NAMESPACE = "restbucks";

	public @Bean CurieProvider curieProvider() {
		return new DefaultCurieProvider(CURIE_NAMESPACE, new UriTemplate("/docs/{rel}.html"));
	}

	/**
	 * Bootstraps the application in standalone mode (i.e. java -jar).
	 * 
	 * @param args
	 */
	public static void main(String[] args) {
		SpringApplication.run(Restbucks.class, args);
	}
}
