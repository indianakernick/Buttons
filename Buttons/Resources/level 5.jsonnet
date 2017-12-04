[
  {
    "file": "platform entity.json",
    "components": {
      "PhysicsBody": {
        "body": "platform body.json",
        "pos": [-16, -9],
        "scale": [32, 7]
      }
    }
  },
  {
    "file": "platform entity.json",
    "components": {
      "PhysicsBody": {
        "body": "platform body.json",
        "pos": [-16, -2],
        "scale": [9, 4]
      }
    }
  },
  {
    "file": "platform entity.json",
    "components": {
      "PhysicsBody": {
        "body": "platform body.json",
        "pos": [-16, 2],
        "scale": [32, 7]
      }
    }
  },
  {
    "file": "platform entity.json",
    "components": {
      "PhysicsBody": {
        "body": "platform body.json",
        "pos": [7, -2],
        "scale": [9, 4]
      }
    }
  },
  {
    "file": "platform entity.json",
    "components": {
      "PhysicsBody": {
        "body": "platform body.json",
        "pos": [-3, -1],
        "scale": [10, 1]
      }
    }
  },
  {
    "file": "platform entity.json",
    "components": {
      "PhysicsBody": {
        "body": "platform body.json",
        "pos": [1, 0],
        "scale": [2, 2]
      }
    }
  },
  {
    "file": "player entity.json",
    "components": {
      "PhysicsBody": {
        "body": "player body.json",
        "pos": [-7, -2]
      }
    }
  },
  {
    "file": "exit entity.json",
    "components": {
      "PhysicsBody": {
        "body": "sensor body.json",
        "pos": [6, -2]
      }
    }
  },
  {
    "file": "box entity.json",
    "components": {
      "PhysicsBody": {
        "body": "box body.json",
        "pos": [3, 0]
      }
    }
  },
  {
    "file": "switch entity.json",
    "components": {
      "PhysicsBody": {
        "body": "sensor body.json",
        "pos": [0, 0]
      }
    }
  },
  {
    "file": "button entity.json",
    "components": {
      "PhysicsBody": {
        "body": "button body.json",
        "pos": [6, 0]
      }
    }
  },
  {
    "id": 0,
    "file": "switch entity.json",
    "components": {
      "PhysicsBody": {
        "body": "sensor body.json",
        "pos": [0, -2]
      }
    }
  },
  {
    "id": 1,
    "file": "button entity.json",
    "components": {
      "PhysicsBody": {
        "body": "button body.json",
        "pos": [3, 0]
      }
    }
  },
  {
    "file": "door entity.json",
    "components": {
      "MultiPowerInput": {
        "in": [0, 1],
        "operator": "and"
      },
      "PhysicsBody": {
        "body": "door body.json",
        "pos": [3.5, -2]
      }
    }
  },
  {
    "id": 2,
    "file": "laser emitter entity.json",
    "components": {
      "PhysicsRayCast": {
        "end": [-3, -0.5],
        "start": [-7, -0.5]
      },
      "PowerInput": {
        "on": true
      },
      "Transform": {
        "pos": [-7, -0.5],
        "rotation": -90
      }
    }
  },
  {
    "id": 3,
    "file": "laser detector entity.json",
    "components": {
      "LaserDetector": {
        "emitter": 2
      },
      "Transform": {
        "pos": [-3, -0.5],
        "rotation": 90
      }
    }
  },
  {
    "file": "moving platform entity.json",
    "components": {
      "MovingPlatform": {
        "end": [3, 0],
        "speed": 10,
        "start": [2, 0]
      },
      "PhysicsBody": {
        "body": "platform body.json",
        "pos": [2, 0],
        "scale": [1, 2]
      },
      "PowerInput": {
        "in": 3,
        "invert": true
      }
    }
  },
  {
    "file": "text entity.json",
    "components": {
      "Text": "Press R to reload the level",
      "Transform": {
        "pos": [0, 4]
      }
    }
  }
]
