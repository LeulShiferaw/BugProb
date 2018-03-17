#include <iostream>

#include "bug.h"
#include "cell.h"
#include "instruction.h"
#include "marker.h"
#include "world.h"

#include "gtest/gtest.h"

TEST(Buggy, BugCreation) {
  Bug bug1(1, "black");
  Bug bug_ptr1(bug1);
  bug1.SetState(10);
  bug1.SetResting(5);
  bug1.SetDirection(2);
  bug1.SetHasFood(1);
  EXPECT_EQ(1, bug_ptr1.GetId());
  EXPECT_EQ("black", bug1.GetColor());
  EXPECT_EQ(10, bug1.GetCurrentState());
  EXPECT_EQ(5, bug1.GetResting());
  EXPECT_EQ(2, bug1.GetDirection());
  EXPECT_EQ(0, bug1.GetNumberOfFoodCarried());
  EXPECT_EQ(1, bug1.HasFood());
  EXPECT_EQ(0, bug1.IsDead());
  bug1.Dead();
  EXPECT_EQ(1, bug1.IsDead());
  EXPECT_THROW(bug1.SetState(10000), std::invalid_argument);
  EXPECT_THROW(bug1.SetDirection(6), std::invalid_argument);
}

TEST(Buggy, BugPosition) {
  World w;
  w.CellAt(std::make_pair(1,2)).SetBug(Bug(23, "red"));
  EXPECT_EQ(1, w.CellAt(std::make_pair(1,2)).GetBug().GetPosition().first);
  EXPECT_EQ(2, w.CellAt(std::make_pair(1,2)).GetBug().GetPosition().second);
}

TEST(Buggy, WorldInitialization) {
  World w;
  EXPECT_EQ(1, w.CellAt(std::make_pair(1,2)).GetCoordinate().first);
  EXPECT_EQ(NULL, w.CellAt(std::make_pair(10,10)).GetCoordinate().first);
  EXPECT_EQ(0, w.CellAt(std::make_pair(3,4)).IsOccupied());
  EXPECT_EQ("black", w.OtherColor("red"));
  EXPECT_EQ("red", w.OtherColor("black"));
  EXPECT_THROW(w.OtherColor("pink"), std::invalid_argument);
}

TEST(Buggy, CellBugAssignment) {
  World w;
  Bug bug1(23, "black");
  w.CellAt(std::make_pair(1,2)).SetBug(bug1);
  EXPECT_EQ(1, w.CellAt(std::make_pair(1,2)).IsOccupied());
  EXPECT_EQ("black", w.CellAt(std::make_pair(1,2)).GetBug().GetColor());
  EXPECT_EQ(23, w.CellAt(std::make_pair(1,2)).GetBug().GetId());
}

TEST(Buggy, CellBasicFunctions) {
  Cell cell1(std::make_pair(2,3), false);
  Bug bug1(23, "red");
  EXPECT_EQ(2, cell1.GetCoordinate().first);
  EXPECT_EQ(3, cell1.GetCoordinate().second);
  EXPECT_EQ(0, cell1.IsObstructed());
  EXPECT_EQ(0, cell1.IsOccupied());
  cell1.SetBug(bug1);
  EXPECT_EQ(1, cell1.IsOccupied());
  EXPECT_EQ(0, cell1.GetNumberOfFood());
  cell1.SetFood(5);
  EXPECT_EQ(5, cell1.GetNumberOfFood());
}

TEST(Buggy, CellSensingFunction) {
  World w;

  // Adjacent cell
  EXPECT_EQ(2, w.CellAt(std::make_pair(1,1)).AdjacentCell(0).first);
  EXPECT_EQ(1, w.CellAt(std::make_pair(1,1)).AdjacentCell(0).second);
  EXPECT_EQ(2, w.CellAt(std::make_pair(1,1)).AdjacentCell(1).first);
  EXPECT_EQ(2, w.CellAt(std::make_pair(1,1)).AdjacentCell(1).second);
  EXPECT_EQ(1, w.CellAt(std::make_pair(1,1)).AdjacentCell(2).first);
  EXPECT_EQ(2, w.CellAt(std::make_pair(1,1)).AdjacentCell(2).second);
  EXPECT_EQ(0, w.CellAt(std::make_pair(1,1)).AdjacentCell(3).first);
  EXPECT_EQ(1, w.CellAt(std::make_pair(1,1)).AdjacentCell(3).second);
  EXPECT_EQ(1, w.CellAt(std::make_pair(1,1)).AdjacentCell(4).first);
  EXPECT_EQ(0, w.CellAt(std::make_pair(1,1)).AdjacentCell(4).second);
  EXPECT_EQ(2, w.CellAt(std::make_pair(1,1)).AdjacentCell(5).first);
  EXPECT_EQ(0, w.CellAt(std::make_pair(1,1)).AdjacentCell(5).second);
  EXPECT_THROW(w.CellAt(std::make_pair(1,1)).AdjacentCell(7), std::invalid_argument);
  // Edge detection was not implemented as mentioned by the Professor in CellBugAssignment

  // Turn left
  EXPECT_EQ(5, w.CellAt(std::make_pair(1,1)).Turn("left", 0));
  EXPECT_EQ(0, w.CellAt(std::make_pair(1,1)).Turn("left", 1));
  EXPECT_EQ(1, w.CellAt(std::make_pair(1,1)).Turn("left", 2));
  EXPECT_EQ(2, w.CellAt(std::make_pair(1,1)).Turn("left", 3));
  EXPECT_EQ(3, w.CellAt(std::make_pair(1,1)).Turn("left", 4));
  EXPECT_EQ(4, w.CellAt(std::make_pair(1,1)).Turn("left", 5));

  // Turn right
  EXPECT_EQ(1, w.CellAt(std::make_pair(1,1)).Turn("right", 0));
  EXPECT_EQ(2, w.CellAt(std::make_pair(1,1)).Turn("right", 1));
  EXPECT_EQ(3, w.CellAt(std::make_pair(1,1)).Turn("right", 2));
  EXPECT_EQ(4, w.CellAt(std::make_pair(1,1)).Turn("right", 3));
  EXPECT_EQ(5, w.CellAt(std::make_pair(1,1)).Turn("right", 4));
  EXPECT_EQ(0, w.CellAt(std::make_pair(1,1)).Turn("right", 5));

  EXPECT_THROW(w.CellAt(std::make_pair(1,1)).Turn("right", 7), std::invalid_argument);

  // CELL SENSING
  EXPECT_EQ(1, w.CellAt(std::make_pair(1,1)).SensedCell(0, "here").first);
  EXPECT_EQ(1, w.CellAt(std::make_pair(1,1)).SensedCell(0, "here").second);
  EXPECT_EQ(2, w.CellAt(std::make_pair(1,1)).SensedCell(0, "ahead").first);
  EXPECT_EQ(1, w.CellAt(std::make_pair(1,1)).SensedCell(0, "ahead").second);
  EXPECT_EQ(2, w.CellAt(std::make_pair(1,1)).SensedCell(0, "leftAhead").first);
  EXPECT_EQ(0, w.CellAt(std::make_pair(1,1)).SensedCell(0, "leftAhead").second);
  EXPECT_EQ(2, w.CellAt(std::make_pair(1,1)).SensedCell(0, "rightAhead").first);
  EXPECT_EQ(2, w.CellAt(std::make_pair(1,1)).SensedCell(0, "rightAhead").second);
  EXPECT_THROW(w.CellAt(std::make_pair(1,1)).SensedCell(0, "behind"), std::invalid_argument);
}

TEST(Buggy, Markers) {
  Marker mark("red", 2);
  EXPECT_EQ("red", mark.GetMarkerColor());
  EXPECT_EQ(2, mark.GetMarkerInt());
  mark.SetMarkerColor("black");
  mark.SetMarkerInt(5);
  EXPECT_EQ("black", mark.GetMarkerColor());
  EXPECT_EQ(5, mark.GetMarkerInt());
}

GTEST_API_ int main(int argc, char **argv) {
  std::cout << "Running test..." << std::endl;
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
