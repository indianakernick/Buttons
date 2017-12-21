local common = import "common.jsonnet";

function(params) {
  [if "id" in params then "id"]: params.id,
  components: common.checkParams(params, ["id", "pos", "orient"]) {
    Activation: {
      speed: 8
    },
    Animation: {
      speed: 0
    },
    AnimSpriteRendering: {
      sprite: "button top 0",
      frames: 5
    },
    StaticSpriteRendering: {
      sprite: "button bottom",
      offset: [0.0, -1.0]
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
