/*
 * Copyright 2016 the original author or authors.
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
package org.springsource.restbucks.payment.web;

import static org.hamcrest.CoreMatchers.*;
import static org.junit.Assert.*;

import java.util.Locale;

import javax.money.MonetaryAmount;

import org.javamoney.moneta.Money;
import org.junit.Before;
import org.junit.Test;
import org.springframework.context.i18n.LocaleContextHolder;
import org.springsource.restbucks.JacksonTestUtils;
import org.springsource.restbucks.core.Currencies;

import com.fasterxml.jackson.databind.ObjectMapper;

/**
 * Unit tests for serialization and deserialization of {@link MonetaryAmount} values.
 * 
 * @author Oliver Gierke
 */
public class MoneySerializationTest {

	ObjectMapper mapper;

	@Before
	public void setUp() {

		this.mapper = new ObjectMapper();
		this.mapper.registerModules(JacksonTestUtils.getModules());

		LocaleContextHolder.setLocale(Locale.ROOT);
	}

	/**
	 * @see #50
	 */
	@Test
	public void serializesMonetaryAmount() throws Exception {
		assertThat(mapper.writeValueAsString(Money.of(4.20, Currencies.EURO)), is("\"EUR 4.20\""));
	}

	/**
	 * @see #50
	 */
	@Test
	public void deserializesMonetaryAmount() throws Exception {
		assertThat(mapper.readValue("\"EUR 4.20\"", MonetaryAmount.class), is(Money.of(4.20, Currencies.EURO)));
	}
}
