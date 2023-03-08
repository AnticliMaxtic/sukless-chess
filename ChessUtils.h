#pragma once

#include <vector>
#include "Piece.h"
#include "common_enums.h"

class ChessUtils {
  public:
    using Field = std::vector<std::vector<Piece>>;
    std::vector<Move> GPM_Piece(Piece p, Field b);
    std::vector<Move> GAPM_Opposing(Color c, Field b);
    std::vector<Move> rookPossible(Piece p, Field b);
    std::vector<Move> bishopPossible(Piece p, Field b);
    const bool isColorInCheck(Color c, Field b);
    Point getKing(Color c, Field b);
    void move(Move m, Field& b);
    bool containsPoint(int x, int y, std::vector<Move> possible);
    std::string board_to_fen(Field b);
    Field fen_to_board(std::string fen);
    PieceType fen_to_type(char c);

    constexpr bool validPoint(int x, int y) const {
      return (x >= 0 && x < 8) && (y >=0 && y < 8);
    }
};