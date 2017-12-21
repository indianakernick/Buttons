local common = import "common.jsonnet";

function(params) {
  [if "id" in params then "id"]: params.id,
  components: common.checkParams(params, ["id", "pos", "orient", "emitter"]) {
    Activation: {
      speed: 8
    },
    Animation: {
      speed: 0
    },
    AnimSpriteRendering: {
      sprite: "laser detector 0",
      frames: 5
    },
    PowerOutput: {},
    Transform: common.getOrientTransform(params),
    LaserDetector: {
      emitter: params.emitter
    }
  }
}
