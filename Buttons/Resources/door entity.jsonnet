local common = import "common.jsonnet";

local validNames = ["active", "on", "in", "operator", "pos", "orient", "height"];

function(params) {
  components: common.checkParams(params, validNames) {
    Activation: common.getActive(params) + {
      speed: 4
    },
    Animation: {
      speed: 0
    },
    AnimSpriteRendering: {
      sprite: "door 0",
      frames: 5,
      offset: [0.0, -0.5],
      scale: [1.0, 1.5],
      depth: common.getDepth("door")
    },
    Door: {},
    Transform: {},
    PhysicsBody: common.getOrientTransform(params) + {
      scale: if "height" in params then
        [1, params.height]
      else
        [1, 1]
      ,
      body: "door body.json"
    },
    PowerInput: common.getPowerInput(params)
  }
}
