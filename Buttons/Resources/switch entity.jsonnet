local common = import "common.jsonnet";

function(params) {
  [if "id" in params then "id"]: params.id,
  components: common.checkParams(params, ["id", "pos", "orient"]) {
    Activation: {
      speed: 4
    },
    ActiveSpriteRendering: {
      sprite: "switch 0",
      frames: 5
    },
    Collision: {},
    PowerOutput: {},
    Switch: {},
    Transform: {},
    PhysicsBody: common.getOrientTransform(params) + {
      body: "sensor body.json"
    }
  }
}
