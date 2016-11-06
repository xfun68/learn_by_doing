/*
 * Copyright 2012-2015 the original author or authors.
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
package org.springsource.restbucks.payment;

import static org.hamcrest.CoreMatchers.*;
import static org.junit.Assert.*;
import static org.springsource.restbucks.order.OrderRepositoryIntegrationTest.*;
import static org.springsource.restbucks.payment.CreditCardRepositoryIntegrationTest.*;

import java.util.Optional;

import org.junit.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springsource.restbucks.AbstractIntegrationTest;
import org.springsource.restbucks.order.Order;
import org.springsource.restbucks.order.OrderRepository;

/**
 * Integration tests for {@link PaymentRepository}.
 * 
 * @author Oliver Gierke
 */
public class PaymentRepositoryIntegrationTest extends AbstractIntegrationTest {

	@Autowired PaymentRepository payments;
	@Autowired CreditCardRepository creditCards;
	@Autowired OrderRepository orders;

	@Test
	public void savesCreditCardPayment() {

		CreditCard creditCard = creditCards.save(createCreditCard());
		Order order = orders.save(createOrder());

		CreditCardPayment payment = payments.save(new CreditCardPayment(creditCard, order));

		assertThat(payment.getId(), is(notNullValue()));
		assertThat(payments.findByOrder(order), is(Optional.of(payment)));
	}
}
