local common = import "common components.jsonnet";

function(params) {
  id: params.id,
  components: {
    Activation: {},
    LaserEmitterRendering: {},
    PowerInput: common.powerInputParams(params),
    PhysicsRayCast: {
      start: params.start,
      end: params.end
    },
    Transform: {
      pos: params.start,
      [if "rotation" in params then "rotation"]: params.rotation
    }
  }
}
