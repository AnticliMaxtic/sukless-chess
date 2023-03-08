#include <catch2/catch_all.hpp>

#include <Piece.h>


TEST_CASE("Piece::Piece()") {
    Piece p;
    REQUIRE(p.type == PieceType::NONE);
    REQUIRE(p.color == Color::C_NONE);
}
