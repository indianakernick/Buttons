[
  {
    "file": "box entity.json",
    "components": {
      "PhysicsBody": {
        "body": "box body.json",
        "pos": [-5, 0],
        "scale": [1, 1]
      }
    }
  },
  {
    "file": "platform entity.json",
    "components": {
      "PhysicsBody": {
        "body": "platform body.json",
        "pos": [-16, -9],
        "scale": [32, 1]
      }
    }
  },
  {
    "file": "player entity.json",
    "components": {
      "PhysicsBody": {
        "body": "player body.json",
        "pos": [0, 0]
      }
    }
  },
  {
    "file": "door entity.json",
    "components": {
      "PhysicsBody": {
        "body": "door body.json",
        "pos": [7.5, -8],
        "scale": [1, 4]
      },
      "PowerInput": {
        "in": 0
      }
    }
  },
  {
    "id": 0,
    "file": "button entity.json",
    "components": {
      "PhysicsBody": {
        "body": "button body.json",
        "pos": [5, -8]
      }
    }
  },
  {
    "file": "door entity.json",
    "components": {
      "PhysicsBody": {
        "body": "door body.json",
        "pos": [8.5, -8],
        "scale": [1, 4]
      },
      "PowerInput": {
        "in": 1
      }
    }
  },
  {
    "id": 1,
    "file": "switch entity.json",
    "components": {
      "PhysicsBody": {
        "body": "switch body.json",
        "pos": [-7.5, -8],
        "scale": [1, 1]
      }
    }
  },
  {
    "file": "exit entity.json",
    "components": {
      "PhysicsBody": {
        "body": "switch body.json",
        "pos": [14.5, -8],
        "scale": [1, 1]
      }
    }
  },
  {
    "file": "moving platform entity.json",
    "components": {
      "MovingPlatform": {
        "end": [-16, 0],
        "speed": 0.1,
        "start": [-16, -9]
      },
      "PhysicsBody": {
        "body": "platform body.json",
        "pos": [-16, -9],
        "scale": [4, 1]
      },
      "PowerInput": {
        "in": 2
      }
    }
  },
  {
    "id": 2,
    "file": "switch entity.json",
    "components": {
      "PhysicsBody": {
        "body": "switch body.json",
        "pos": [-2, -8],
        "scale": [1, 1]
      }
    }
  },
  {
    "file": "laser detector entity.json",
    "components": {
      "LaserDetector": {
        "emitter": 3
      },
      "Transform": {
        "pos": [16, 4],
        "rotation": 90
      }
    }
  },
  {
    "id": 3,
    "file": "laser emitter entity.json",
    "components": {
      "PhysicsRayCast": {
        "end": [16, 4],
        "start": [-15, 4]
      },
      "PowerInput": {
        "on": true
      },
      "Transform": {
        "pos": [-16, 4],
        "rotation": -90
      }
    }
  },
  {
    "id": 4,
    "file": "lock entity.json",
    "components": {
      "Lock": {
        "index": 0
      },
      "PhysicsBody": {
        "body": "switch body.json",
        "pos": [-7.5, -6]
      }
    }
  },
  {
    "file": "key entity.json",
    "components": {
      "Key": {
        "index": 0
      },
      "PhysicsBody": {
        "body": "switch body.json",
        "pos": [-2, -6]
      }
    }
  },
  {
    "file": "shadow entity.json",
    "components": {
      "PowerInput": {
        "in": 4
      },
      "Transform": {
        "pos": [10, -8],
        "scale": [6, 4]
      }
    }
  }
]