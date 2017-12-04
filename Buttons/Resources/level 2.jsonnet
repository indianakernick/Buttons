local e = import "entities.jsonnet";

[
  e.platform.makePosSize([-16, -9], [32, 8]),
  e.platform.makePosSize([-16, 1], [32, 8]),
  e.platform.makePosSize([-16, -1], [1, 2]),
  e.platform.makePosSize([15, -1], [1, 2]),
  e.player.makePos([-15, -1]),
  e.exit.makePos([14, -1]),
  e.door.makeInPosSizeRot(0, [5.5, 1], [1, 2], 180),
  e.switch.makeIdPos(0, [-5, -1]),
  e.text.makePosText([0, 2], "Press space to toggle switches")
]
