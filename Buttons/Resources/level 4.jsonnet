local e = import "entities.jsonnet";

std.flattenArrays([[
  e.makeSwitch({
    id: i,
    pos: [-5 + i * 3, -5]
  }) for i in std.makeArray(4, function(x) x)
], [
  e.makePlatform({
    pos: [-16, -9],
    size: [32, 4]
  }),
  e.makePlatform({
    pos: [-15, -1],
    size: [30, 2]
  }),
  e.makePlatform({
    pos: [-16, 5],
    size: [32, 4]
  }),
  e.makePlatform({
    pos: [-16, -5],
    size: [1, 10]
  }),
  e.makePlatform({
    pos: [15, -5],
    size: [1, 10]
  }),
  e.makePlayer({
    pos: [-15, -5]
  }),
  e.makeExit({
    pos: [14, -5]
  }),
  e.door.makeInPosSize(5, [9.5, -5], [1, 4]),
  e.laser_emitter.makeIdStartEndRot(4, [-15, 3], [15, 3], -90),
  e.laser_detector.makeIdEmitterPosRot(5, 4, [15, 3], 90),

  {
    "file": "door entity.json",
    "components": {
      "MultiPowerInput": {
        "in": [0, 1],
        "operator": "or"
      },
      "PhysicsBody": {
        "body": "door body.json",
        "pos": [-10.5, 1],
        "scale": [1, 4]
      }
    }
  },
  {
    "file": "door entity.json",
    "components": {
      "MultiPowerInput": {
        "in": [0, 2],
        "operator": "xor"
      },
      "PhysicsBody": {
        "body": "door body.json",
        "pos": [-3.5, 1],
        "scale": [1, 4]
      }
    }
  },
  {
    "file": "door entity.json",
    "components": {
      "PhysicsBody": {
        "body": "door body.json",
        "pos": [3.5, 1],
        "scale": [1, 4]
      },
      "PowerInput": {
        "in": 2
      }
    }
  },
  {
    "file": "door entity.json",
    "components": {
      "PhysicsBody": {
        "body": "door body.json",
        "pos": [10.5, 1],
        "scale": [1, 4]
      },
      "PowerInput": {
        "in": 3,
        "invert": true
      }
    }
  }
]])
