[
  {
    "file": "platform entity.json",
    "components": {
      "PhysicsBody": {
        "body": "platform body.json",
        "pos": [-16, -9],
        "scale": [32, 4]
      }
    }
  },
  {
    "file": "platform entity.json",
    "components": {
      "PhysicsBody": {
        "body": "platform body.json",
        "pos": [-15, -1],
        "scale": [30, 2]
      }
    }
  },
  {
    "file": "platform entity.json",
    "components": {
      "PhysicsBody": {
        "body": "platform body.json",
        "pos": [-16, 5],
        "scale": [32, 4]
      }
    }
  },
  {
    "file": "platform entity.json",
    "components": {
      "PhysicsBody": {
        "body": "platform body.json",
        "pos": [-16, -5],
        "scale": [1, 10]
      }
    }
  },
  {
    "file": "platform entity.json",
    "components": {
      "PhysicsBody": {
        "body": "platform body.json",
        "pos": [15, -5],
        "scale": [1, 10]
      }
    }
  },
  {
    "file": "player entity.json",
    "components": {
      "PhysicsBody": {
        "body": "player body.json",
        "pos": [-15, -5]
      }
    }
  },
  {
    "file": "exit entity.json",
    "components": {
      "PhysicsBody": {
        "body": "sensor body.json",
        "pos": [14, -5]
      }
    }
  },
  {
    "file": "door entity.json",
    "components": {
      "PhysicsBody": {
        "body": "door body.json",
        "pos": [9.5, -5],
        "scale": [1, 4]
      },
      "PowerInput": {
        "in": 5
      }
    }
  },
  {
    "id": 4,
    "file": "laser emitter entity.json",
    "components": {
      "PhysicsRayCast": {
        "end": [15, 3],
        "start": [-15, 3]
      },
      "PowerInput": {
        "on": true
      },
      "Transform": {
        "pos": [-15, 3],
        "rotation": -90
      }
    }
  },
  {
    "id": 5,
    "file": "laser detector entity.json",
    "components": {
      "LaserDetector": {
        "emitter": 4
      },
      "Transform": {
        "pos": [15, 3],
        "rotation": 90
      }
    }
  },
  {
    "id": 0,
    "file": "switch entity.json",
    "components": {
      "PhysicsBody": {
        "body": "sensor body.json",
        "pos": [-5, -5]
      }
    }
  },
  {
    "id": 1,
    "file": "switch entity.json",
    "components": {
      "PhysicsBody": {
        "body": "sensor body.json",
        "pos": [-2, -5]
      }
    }
  },
  {
    "id": 2,
    "file": "switch entity.json",
    "components": {
      "PhysicsBody": {
        "body": "sensor body.json",
        "pos": [1, -5]
      }
    }
  },
  {
    "id": 3,
    "file": "switch entity.json",
    "components": {
      "PhysicsBody": {
        "body": "sensor body.json",
        "pos": [4, -5]
      }
    }
  },
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
]