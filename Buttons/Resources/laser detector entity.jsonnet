local common = import "common components.jsonnet";

function(params) {
  [if "id" in params then "id"]: params.id,
  components: {
    Activation: {},
    LaserDetectorRendering: {},
    PowerOutput: {},
    Transform: common.transformParams(params),
    LaserDetector: {
      emitter: params.emitter
    }
  }
}
