local common = import "common.jsonnet";

function(params) {
  [if "id" in params then "id"]: params.id,
  components: {
    Activation: {},
    LaserDetectorRendering: {},
    PowerOutput: {},
    Transform: common.getOrientTransform(params),
    LaserDetector: {
      emitter: params.emitter
    }
  }
}
