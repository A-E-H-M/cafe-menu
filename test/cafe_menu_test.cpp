
#include <catch2/catch_test_macros.hpp>
#include <vector>

#include "cafe_menu_iostream.hpp"

using namespace cafe_menu;

TEST_CASE( "Initialize menu_item", "[menu_item]" ) {
	menu_item monday_menu;
	std::string x = "";

	CHECK( monday_menu.item_name == x );
	REQUIRE( monday_menu.item_price == 0.0  );
	REQUIRE( monday_menu.item_num == 0  );

}

TEST_CASE( "Initalize invoice", "[invoice]" ) {
	invoice order_1;

	REQUIRE( order_1.tax == 0.0 );
	REQUIRE( order_1.sub_total == 0.0 );
	REQUIRE( order_1.tax_total == 0.0 );
	REQUIRE( order_1.total == 0.0 );
}

TEST_CASE( "", "[]" ){
	
}
