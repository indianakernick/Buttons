local common = import "common.jsonnet";

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
    Transform: common.transformParams(params) + {
      pos: params.start,
    }
  }
}
