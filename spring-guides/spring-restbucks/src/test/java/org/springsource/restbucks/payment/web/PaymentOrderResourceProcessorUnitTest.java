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
package org.springsource.restbucks.payment.web;

import static org.hamcrest.Matchers.*;
import static org.junit.Assert.*;
import static org.mockito.Mockito.*;
import static org.springsource.restbucks.order.Order.Status.*;

import javax.servlet.http.HttpServletRequest;

import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mock;
import org.mockito.Mockito;
import org.mockito.runners.MockitoJUnitRunner;
import org.springframework.hateoas.Link;
import org.springframework.hateoas.Resource;
import org.springframework.mock.web.MockHttpServletRequest;
import org.springframework.web.context.request.RequestContextHolder;
import org.springframework.web.context.request.ServletRequestAttributes;
import org.springsource.restbucks.order.Order;
import org.springsource.restbucks.order.Order.Status;
import org.springsource.restbucks.order.TestUtils;

/**
 * Unit test for {@link PaymentOrderResourceProcessorUnitTest}.
 * 
 * @author Oliver Gierke
 */
@RunWith(MockitoJUnitRunner.class)
public class PaymentOrderResourceProcessorUnitTest {

	@Mock PaymentLinks paymentLinks;

	PaymentOrderResourceProcessor processor;
	Link paymentLink, receiptLink;

	@Before
	public void setUp() {

		HttpServletRequest request = new MockHttpServletRequest();
		ServletRequestAttributes requestAttributes = new ServletRequestAttributes(request);
		RequestContextHolder.setRequestAttributes(requestAttributes);

		paymentLink = new Link("payment", PaymentLinks.PAYMENT_REL);
		receiptLink = new Link("receipt", PaymentLinks.RECEIPT_REL);

		processor = new PaymentOrderResourceProcessor(paymentLinks);
		when(paymentLinks.getPaymentLink(Mockito.any(Order.class))).thenReturn(paymentLink);
		when(paymentLinks.getReceiptLink(Mockito.any(Order.class))).thenReturn(receiptLink);
	}

	@Test
	public void doesNotAddLinksForNeitherFreshNorUnfinishedOrders() {

		for (Status status : Status.values()) {

			if (status == READY || status == PAYMENT_EXPECTED) {
				continue;
			}

			Order order = TestUtils.createExistingOrderWithStatus(status);
			Resource<Order> resource = processor.process(new Resource<Order>(order));

			assertThat(resource.hasLinks(), is(false));
		}
	}

	@Test
	public void addsPaymentLinkForFreshOrder() {

		Order order = TestUtils.createExistingOrder();

		Resource<Order> resource = processor.process(new Resource<Order>(order));
		assertThat(resource.getLink(PaymentLinks.PAYMENT_REL), is(paymentLink));
	}

	@Test
	public void addsReceiptLinkForPaidOrder() {

		Order order = TestUtils.createExistingOrder();
		order.markPaid();
		order.markInPreparation();
		order.markPrepared();

		Resource<Order> resource = processor.process(new Resource<Order>(order));
		assertThat(resource.getLink(PaymentLinks.RECEIPT_REL), is(receiptLink));
	}
}
