local common = import "common.jsonnet";

local startPosTable = {
  up: [0.5, 0.0],
  right: [0.0, 0.5],
  down: [0.5, 1.0],
  left: [1.0, 0.5]
};

local endPosTable = {
  up: [0.5, 1.0],
  right: [1.0, 0.5],
  down: [0.5, 0.0],
  left: [0.0, 0.5]
};

function(params) {
  id: params.id,
  components: {
    Activation: {},
    LaserEmitterRendering: {},
    PowerInput: common.getPowerInput(params),
    PhysicsRayCast: {
      start: common.add(params.start, common.lookupOrient(params, startPosTable)),
      end: common.add(params.end, common.lookupOrient(params, endPosTable)),
    },
    Transform: common.getOrientTransform(params + {pos: params.start})
  }
}
