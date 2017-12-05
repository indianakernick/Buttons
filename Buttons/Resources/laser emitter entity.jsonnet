local common = import "common.jsonnet";

function(params) {
  id: params.id,
  components: {
    Activation: {},
    LaserEmitterRendering: {},
    PowerInput: common.getPowerInput(params),
    PhysicsRayCast: {
      start: params.start,
      end: params.end
    },
    Transform: common.getTransform(params) + {
      pos: params.start,
    }
  }
}
