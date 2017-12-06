local common = import "common.jsonnet";

function(params) {
  components: {
    Activation: {
      speed: 0.5
    },
    ShadowRendering: {},
    Transform: common.getPosSize(params)
  }
}
