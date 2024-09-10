
#include <catch2/catch_test_macros.hpp>
#include <vector>

#include "cafe_menu_iostream.hpp"

using namespace cafe_menu;

TEST_CASE( "Initialize menu_item", "[menu_item]" ) {
	menu_item ex_item;
	std::string x;

	CHECK( ex_item.name == x );
	REQUIRE( ex_item.price == 0.0  );
	REQUIRE( ex_item.num == 0  );

}

/*
TEST_CASE( "Initalize menu", "[menu]") {
	menu ex_menu;
	
}
*/

/*
TEST_CASE( "Initalize ordered_item", "[ordered_item]") {
	ordered_item ex_item;

	REQUIRE( ex_item.item_num == 0.0 );
	REQUIRE( ex_item.num_of_item == 0.0 );
	REQUIRE( ex_item.multiple_item == false );
}

TEST_CASE( "Initalize discounts", "[discounts]") {
	discounts ex_discount;
	std::string x = "";

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
*/
/*
TEST_CASE( "Initalize order", "[order]" ){
	order ex_order;
	
}
*/

/*
TEST_CASE( "Returning a vector from parsed text file", "[create_menu]" ){
	
}
*/

/*
TEST_CASE( "Calculating the subtotal", "[calc_sub_total]") {
	
}
*/
/*
TEST_CASE( "Calculating discounts", "[calc_discounts]" ) {
	REQUIRE( calc_discounts(10, .05) == .5 );
	REQUIRE( calc_discounts(32.5, .05) == 1.625 );
	REQUIRE( calc_discounts(420.26, .75) == 315.195 );
	REQUIRE( calc_discounts(-25.0, .17) == -4.25 );
}

TEST_CASE( "Caculating subtotal tax", "[calc_sub_total_tax]") {
	REQUIRE( calc_sub_total_tax(10, .05) == .5 );	
	REQUIRE( calc_sub_total_tax(32.5, .05) == 1.625 );
	REQUIRE( calc_sub_total_tax(420.26, .75) == 315.195 );
	REQUIRE( calc_sub_total_tax(-25.0, .17) == -4.25 );

}

TEST_CASE( "Calculating total", "[calc_total]") {
	REQUIRE( calc_sub_total_tax(10.0, 3.25) == 13.25 );	
	REQUIRE( calc_sub_total_tax(32.5, -59) == -26.5 );
	REQUIRE( calc_sub_total_tax(420, 75) == 495 );
	REQUIRE( calc_sub_total_tax(-25.0, .17) == -24.83 );

}
*/
