local e = import "entities.jsonnet";

[
  e.platform.makePosSize([-16, -9], [32, 1]),
  e.platform.makePosSize([-16, -8], [1, 17]),
  e.platform.makePos([-7, -8]),
  e.platform.makePosSize([-9, -7], [3, 1]),
  e.player.makePos([-15, -8]),
  e.exit.makePos([-8, -8]),
  e.lock.makeIdIndexPos(0, 0, [-11, -8]),
  e.door.makeInPos(0, [-8.5, -8]),
  e.switch.makeIdPos(10, [-13, -8]),
 
  {
    "file": "moving platform entity.json",
    "components": {
      "PhysicsBody": {
        "body": "platform body.json",
        "pos": [-15, -9],
        "scale": [2, 1]
      },
      "PowerInput": {
        "in": 10
      },
      "MovingPlatform": {
        "start": [-15, -9],
        "end": [-15, -1],
        "speed": 0.1,
        "waiting time": 2.0
      }
    }
  },
  e.platform.makePosSize([-13, -1], [5, 1]),
  e.platform.makePos([-9, 0]),
  e.platform.makePosSize([-11, 1], [3, 1]),
  e.key.makeIndexPos(0, [-10, 0]),
  e.lock.makeIdIndexPos(1, 1, [-13, 0]),
  e.door.makeInPos(1, [-10.5, 0])
]
