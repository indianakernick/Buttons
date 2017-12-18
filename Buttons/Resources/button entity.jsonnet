local common = import "common.jsonnet";

function(params) {
  [if "id" in params then "id"]: params.id,
  components: common.checkParams(params, ["id", "pos", "orient"]) {
    Activation: {
      speed: 8
    },
    ActiveSpriteRendering: {
      sprite: "button top 0",
      frames: 5
    },
    Button: {},
    Collision: {},
    PowerOutput: {},
    Transform: {},
    PhysicsBody: common.getOrientTransform(params) + {
      body: "button body.json"
    }
  }
}
