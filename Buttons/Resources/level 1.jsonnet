local e = import "entities.jsonnet";

[
  e.platform.makePosSize([-16, -9], [32, 1]),
  e.platform.makePosSize([-16, 8], [32, 1]),
  e.platform.makePosSize([-16, -8], [1, 16]),
  e.platform.makePosSize([15, -8], [1, 16]),
  e.platform.makePos([-13, -8]),
  e.platform.makePosSize([-8, -8], [1, 2]),
  e.platform.makePosSize([-5, -5], [4, 1]),
  e.platform.makePosSize([3, -8], [1, 4]),
  e.platform.makePosSize([10, -7], [5, 1]),
  e.player.makePos([-15, -8]),
  e.exit.makePos([14, -6]),
  e.text.makePosText([0, 0], "Press W or up to jump")
]
