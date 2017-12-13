local common = import "common.jsonnet";

function(params) {
  components: common.checkParams(params, ["pos", "size"]) {
    Activation: {
      speed: 0.5
    },
    ShadowRendering: {},
    Transform: common.getPosSize(params)
  }
}
