#include <catch2/catch_test_macros.hpp>
#include "../../BabaIsYou/src/game/levelloader.h"

TEST_CASE( "Test of LevelLoader") {
    Board board{LevelLoader::levelLoad(0)};

    SECTION("Test limit"){
        Position pos{0,0};
        vector<Entity> entities = board.getEntities(pos);
        bool res{false};
        for (int i = 0; i < entities.size() && !res; ++i) {
            res = entities[i].getType()==EntityType::ELEMENT && entities[i].getNature() == EntityNature::LIMIT;
        }
        REQUIRE(res);
    }
    SECTION("Test empty"){
        Position pos{1,1};
        bool res = board.getEntities(pos).empty();
        REQUIRE(res);
    }
    SECTION("Test Baba element"){
        Position pos{9,6};
        vector<Entity> entities = board.getEntities(pos);
        bool res{false};
        for (int i = 0; i < entities.size() && !res; ++i) {
            res = entities[i].getType()==EntityType::ELEMENT && entities[i].getNature() == EntityNature::BABA;
        }
        REQUIRE(res);
    }
    SECTION("Test Baba text"){
        Position pos{13,5};
        vector<Entity> entities = board.getEntities(pos);
        bool res{false};
        for (int i = 0; i < entities.size() && !res; ++i) {
            res = entities[i].getType()==EntityType::TEXT && entities[i].getNature() == EntityNature::BABA;
        }
        REQUIRE(res);
    }
    //the same test can be applied to all elements of the board
}
