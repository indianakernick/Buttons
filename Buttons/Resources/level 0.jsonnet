local e = import "entities.jsonnet";

[
  e.platform.makePosSize([-16, -9], [32, 8]),
  e.platform.makePosSize([-16, 1], [32, 8]),
  e.platform.makePosSize([-16, -1], [1, 2]),
  e.platform.makePosSize([15, -1], [1, 2]),
  e.player.makePos([-15, -1]),
  e.exit.makePos([14, -1]),
  e.text.makePosText([0, 2], "Press A and D or left and right to move")
]
