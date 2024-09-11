
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <vector>

#include "cafe_menu_iostream.hpp"

using namespace cafe_menu;

TEST_CASE( "Initialize menu_item", "[menu_item]" ) {
	menu_item ex_item;
	std::string x;

	CHECK( ex_item.name == x );
	REQUIRE( ex_item.price == 0.0 );
	REQUIRE( ex_item.num == 0 );

}

TEST_CASE( "Initalize menu", "[menu]" ) {
	menu ex_menu;
	REQUIRE( ex_menu.all_menu_items.empty() == true );

	SECTION( "Resize all_menu_items vector", "[menu]" ) {
		ex_menu.all_menu_items.resize(10);
		
		REQUIRE( ex_menu.all_menu_items.size() == 10 );
		CHECK( ex_menu.all_menu_items[1].price == 0.0 );
	}

}

TEST_CASE( "Initalize ordered_item", "[ordered_item]" ) {
	ordered_item ex_item;

	REQUIRE( ex_item.item_num == 0.0 );
	REQUIRE( ex_item.num_of_item == 0.0 );
	REQUIRE( ex_item.multiple_item == false );
}

TEST_CASE( "Initalize discounts", "[discounts]" ) {
	discounts ex_discount;
	std::string x;

	REQUIRE( ex_discount.active_discounts == false );
	CHECK( ex_discount.name == x );
	CHECK( ex_discount.type == x );
	REQUIRE( ex_discount.discount_rate == 0.0 );
}

TEST_CASE( "Initalize invoice", "[invoice]" ) {
	invoice ex_invoice;

	REQUIRE( ex_invoice.sales_tax_rate == 0.0 );
	REQUIRE( ex_invoice.discounts_total == 0.0 );
	REQUIRE( ex_invoice.sub_total == 0.0 );
	REQUIRE( ex_invoice.sub_total_tax == 0.0 );
	REQUIRE( ex_invoice.total == 0.0 );
}

TEST_CASE( "Initalize order", "[order]" ){
	order ex_order;
	REQUIRE( ex_order.customer_order.empty() == true );

	SECTION( "Resize customer_order vector", "[order]" ) {
		ex_order.customer_order.resize(10);
		
		REQUIRE( ex_order.customer_order.size() == 10 );
		CHECK( ex_order.customer_order[1].item_num == 0 );
	}

	SECTION( "Change customer_invoice variable members", "[order, invoice]") {
		ex_order.customer_invoice.sub_total = GENERATE(43.03, 9, -130.23);

		CHECK( ex_order.customer_invoice.sub_total == 43.03 );
		CHECK( ex_order.customer_invoice.sub_total == 43.030005 );
		CHECK( ex_order.customer_invoice.sub_total == 9 );
		CHECK( ex_order.customer_invoice.sub_total == 9.00 );
		CHECK( ex_order.customer_invoice.sub_total == -130.23 );
		CHECK( ex_order.customer_invoice.sub_total == -130.230 );
	}

}

/*
TEST_CASE( "Returning a vector from parsed text file", "[create_menu]" ){
	
}
*/

/*
TEST_CASE( "Calculating the subtotal", "[calc_sub_total]") {
	
}
*/

TEST_CASE( "Calculating discounts", "[calc_discounts]" ) {
	
	SECTION( "Generated sub_total", "[calc_discounts]" ) {
		auto sub_total = GENERATE(10, -15, 130.00);

		CHECK( calc_discounts(sub_total, .25) == 2.5 );
	}

	SECTION( "Generated discount_rate", "[calc_discounts]" ) {
		auto discount_rate = GENERATE(.25, .5, 7);

		CHECK( calc_discounts(10, discount_rate) == 5 );
	} 
}

TEST_CASE( "Caculating sub_total_tax", "[calc_sub_total_tax]") {
	
	SECTION( "Generated sub_total", "[calc_sub_total_tax]" ) {
		auto sub_total = GENERATE(10, -15, 130.00);

		CHECK( calc_sub_total_tax(sub_total, .25) == 2.5 );
	}

	SECTION( "Generated sales_tax_rate", "[calc_sub_total_tax]" ) {
		auto sales_tax_rate = GENERATE(.25, .5, 7);

		CHECK( calc_sub_total_tax(10, sales_tax_rate) == 5 );
	}
}


TEST_CASE( "Calculating total", "[calc_total]") {
	SECTION( "Generated sub_total", "[calc_total]" ) {
		auto sub_total = GENERATE(10, -15, 130.00);

		CHECK( calc_total(sub_total, 3.5) == 13.5 );
	}

	SECTION( "Generated sub_total_tax", "[calc_total]" ) {
		auto sub_total_tax = GENERATE(3, 3.5, 25);

		CHECK( calc_total(15.25, sub_total_tax) == 40.25 );
	}
}
